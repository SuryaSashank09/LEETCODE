class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        top = -1
        for i in s:
            if i == "(" or i == "[" or i == "{":
                top += 1
                stack.append(i)
            elif len(stack) > 0:
                if i == ")" and stack[top] == "(":
                    stack.pop()
                    top -= 1
                elif i == "]" and stack[top] == "[":
                    stack.pop()
                    top -= 1
                elif i == "}" and stack[top] == "{":
                    stack.pop()
                    top -= 1
                else:
                    return False
            else:
                return False 
                
        if len(stack) == 0:
            return True
        else:
            return False