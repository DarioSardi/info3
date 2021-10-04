package scala

trait GenericItem{
  val title: String;
  val id:Int;
}

abstract class LibItem(val title:String, val id:Int) extends GenericItem{
  import scala.Subscriber
  import scala.MyLibrary
	def category   :  String 
	def borrowDur  :  Int      
	var borrowed   :  Boolean  = false
	var owner:Subscriber       = null
	var returnDate :  Int      = 0
	
	
	/* check if free
	 * set as borrowed
	 * set owner
	 * set returnDate 
	 */
	def borrow(sub : Subscriber)   :  Boolean  ={
	  if(!borrowed && sub.fee==0){
	    borrowed=true
	    owner=sub
	    returnDate = MyLibrary.todayDate()+borrowDur*(if (sub.isInstanceOf[goldenMember]) 2 else 1)
	    return true
	  }
	  else if(borrowed){
	    println("the book is already borrowed")
	    return false
	  }
	  else if(sub.fee>0) {
	    println("you cannot borrow until you pay the fee")
	    return false
	  }
	  else{
	    println("borr. error")
	    return false
	  }
	
	}
	
	/* check if you are the owner
	 * check if you are not late
	 * set not borrowed
	 * unset owner
	 * reset returnDate 
	 */
	def returnIt(sub : Subscriber) :  Boolean  ={
	  if(owner.id == sub.id){
	    if(MyLibrary.todayDate()>returnDate){
	      if( sub.isInstanceOf[goldenMember]){
	        sub.fee+=((MyLibrary.todayDate()-returnDate)*0.5).toInt
	      }
	      sub.fee+=MyLibrary.todayDate()-returnDate
	    }
	    borrowed = false
	    owner = null
	    returnDate = 0
	    return true
	  }
	  return false
	}
	
	def getInfo: String
}

class Book(val t:String,val i:Int) extends  LibItem(t,i){
    def category = "Book"
    def borrowDur = 90
    def getInfo() = "Book title: "+title+ " ,max borrow: "+borrowDur
}

class EBook(val t:String,val i:Int) extends LibItem(t,i){
  def category = "EBook"
  def borrowDur = 120
  def getInfo() = "EBook title: "+title+ " ,max borrow: "+borrowDur
}

class Media(val t:String,val i:Int) extends  LibItem(t,i){
  def category = "Media"
  def borrowDur = 30
  def getInfo() = "Media title: "+title+ " ,max borrow: "+borrowDur

}