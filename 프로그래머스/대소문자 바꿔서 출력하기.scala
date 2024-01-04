import scala.io.StdIn.readLine

object Solution {
  def main(args: Array[String]) {
    val s1 = readLine()
    val s2 = s1.map{
      case c if c.isUpper => c.toLower
      case c if c.isLower => c.toUpper
    }
    print(s2)
  }
}