import scala.io.StdIn.readLine

object Main {
  def main(args: Array[String]): Unit = {
    val inp = readLine().split(" ")
    val (s1, a) = (inp(0), inp(1).toInt)
    print(s1*a)
  }
}