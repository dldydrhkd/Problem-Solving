object Solution {
  def solution(my_string: String, overwrite_string: String, s: Int): String = {
    val a = my_string.substring(0,s)
    if (s + overwrite_string.length() < my_string.length()){
      val b = my_string.substring(s+overwrite_string.length())
      return (a+overwrite_string+b)
    }
    return a+overwrite_string
  }
}