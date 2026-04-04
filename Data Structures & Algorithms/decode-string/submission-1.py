class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        k = 0
        for char in s:
            if char.isdigit():
                k = k * 10 + int(char)
            elif char == "[":
                stack.append(k)
                stack.append(char)
                k = 0
            elif char != "]":
                stack.append(char)
            elif char == "]":
                substr = ""
                print(stack)
                while stack[-1] != "[":
                    substr += stack.pop()
                stack.pop()
                substr *= stack.pop()
                stack.extend(substr[::-1])
                
        return ''.join(stack)
                    
                


