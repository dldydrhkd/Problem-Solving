class Solution(object):
    def isValid(self, s):
        li = []
        for i in s:
            if(li):
                if(i==')' and li[len(li)-1]=='('):
                    li.pop()
                elif(i==']' and li[len(li)-1]=='['):
                    li.pop()
                elif(i=='}' and li[len(li)-1]=='{'):
                    li.pop()
                else:
                    li.append(i)
            else:
                li.append(i)
        if(li):
            return False
        return True
        