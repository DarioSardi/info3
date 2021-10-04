package scala

import java.nio.file.Paths
import scala.io.Source


object Main {
  import scala.MyLibrary
  import scala.Subscriber
  def main(args: Array[String]): Unit = {
    val lib = MyLibrary
    lib.init()
//    lib.printSubs()
//    lib.people(5).fee=20
//    println(lib.catalogue(0).getInfo);
    lib.people(1).borrowItem(3);
    lib.people(1).borrowItem(4);
    lib.people(1).borrowItem(5);
    lib.people(1).printMyList();
    lib.timeSkip(200);
    lib.people(1).returnItem(3); //FEE TO PAY
    lib.people(1).borrowItem(6); // CANNOT BORROW UNTIL PAY
    lib.people(1).addMoney(500);
    lib.people(1).payFee();
    
    lib.people(1).printMyList();
   
//    lib.printCatalog();
//   lib.administrator.printOverdue()
  }
}