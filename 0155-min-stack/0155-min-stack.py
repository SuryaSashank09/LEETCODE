class MinStack:


    def __init__(self):
        self.stack=[]
        self.minstack=[]
        

    def push(self, value: int) -> None:
        self.stack.append(value)
        if len(self.minstack)==0:
            self.minstack.append(value)
        else:
            self.minstack.append(min(self.minstack[-1],value))
        
    def pop(self) -> None:
        self.stack.pop()
        self.minstack.pop()
        

    def top(self) -> int:
        x = self.stack[-1]
        return x
        

    def getMin(self) -> int:
        return self.minstack[-1]

        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()