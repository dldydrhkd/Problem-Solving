import scala.io.StdIn.readLine

object Solution {
  def main(args: Array[String]) {
    val inp = readLine().split(" ")
    val (s1, s2) = (inp(0), inp(1))
    print(s1+s2)
  }
}