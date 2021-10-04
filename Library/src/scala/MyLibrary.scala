package scala

import java.nio.file.Paths
import scala.io.Source
import scala.collection.mutable.ListBuffer
import sun.security.util.Length



object MyLibrary {
  import scala.LibItem
  import scala.Subscriber
  import scala.util.Random
  var date = 0;
  var catalogue:ListBuffer[LibItem] = new ListBuffer()
  var people:ListBuffer[Subscriber] = new ListBuffer()
  val administrator = admin
  
  def init()={
    initCatalog()
    initSubscribers()
    people+= administrator
  }
  
  def timeSkip(t:Int)={
    date+=t
  }
  
  def addSubscriber(name:String,golden:Boolean)={
    if(golden){
      val sb = new goldenMember(name)
      people+=sb
    }
    else{
      val sb = new Subscriber(name)
      people+=sb
    }
    
  }
  
  def todayDate():Int={
    return date
  }
  def initItem(s:String)={
    var res=s.split(";")
    res(1).toInt match{
    case 0 =>  catalogue+=new Book(res(0),catalogue.size)
    case 1 =>  catalogue+=new EBook(res(0),catalogue.size)
    case 2 =>  catalogue+=new Media(res(0),catalogue.size)
    }
  }
  
  def initCatalog()={
    val filepath = Paths.get("src\\catalogue.csv").toAbsolutePath
    val csvLines = Source.fromFile(filepath.toString).getLines.toList
    csvLines.foreach(initItem(_))
    //printCatalog()
  }
  
  def initSubscribers()={
    val filepath = Paths.get("src\\names.csv").toAbsolutePath
    val csvLines = Source.fromFile(filepath.toString).getLines.toList
    csvLines.foreach(n => addSubscriber(n, Random.nextBoolean()))
  }
  
  def printCatalog()={
    catalogue.foreach(i => println(">"+i.id+" "*(4-i.id.toString.length())+i.title+" "*(30-(i.title.length()))+"status:"+(if (i.borrowed) " taken" else "free")+"\tmore:"+i.getInfo))
  }
  
  def printSubs()={
    people.foreach(p => println(">"+p.name+" "*(35-p.name.length())+"fee: "+p.fee )  )
  }
  
  def getOverdue()={
    people.filter(p => p.fee>0 ).foreach(p => println(">"+p.name+" "*(35-p.name.length())+"fee: "+p.fee )  )
  }
}