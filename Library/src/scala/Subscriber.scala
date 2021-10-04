

package scala

import scala.util.Random
import scala.collection.mutable.ListBuffer



class Subscriber(val name: String) {

  var fee = 0
  var balance = 0
  var id: String = Random.nextInt().toString()
  var myItems:ListBuffer[LibItem] = new ListBuffer()
 
  
  
  def addMoney(amm : Int )={
    balance+=amm
  }
  def payFee():Boolean={
    if (balance>=fee){
      fee=0
      balance-=fee
      println("payment completed")
      return true
    }
    else{
      println("not enough money to pay your fee.\ncurrent fee: "+fee)
      return false
      }
  }
  
  def borrowItem(id : Int)={
    if(MyLibrary.catalogue.filter(p => p.id == id).head.borrow(this)){
      myItems+=MyLibrary.catalogue.filter(p => p.id == id).head;
    }
  }
  
  def returnItem(id : Int)={
    if(!myItems.filter(i => i.id ==id).isEmpty){
      myItems.filter(i => i.id ==id).head.returnIt(this)
      myItems = myItems.filterNot(i=> i.id == id)
    }
  }
  
  def printMyList(){
    println("-"*40+"\nreading list of subscriber "+this.name+"\n"+"-"*40)
    myItems.foreach(i => println(">"+i.id+" "*(4-i.id.toString.length())+i.title))
  }
  
}

class goldenMember(val n:String) extends Subscriber(n){
  def getReadingList(s : Subscriber)={
    s.printMyList()
  }
}

//single obj
object admin extends Subscriber("ADMIN"){
  def printOverdue()={
    println("-"*40+"\noverdue list \n"+"-"*40)
    MyLibrary.getOverdue()
  }
}

