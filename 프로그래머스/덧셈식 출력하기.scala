import scala.io.StdIn.readLine

object Solution {
  def main(args: Array[String]) {
    val n = readLine().split(" ")
    val (a, b) = (n(0).toInt, n(1).toInt)
    println(a + " + " + b + " = " + (a+b))
  }
}