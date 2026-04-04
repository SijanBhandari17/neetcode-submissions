class Solution:
    def simplifyPath(self, path: str) -> str:
        dir = [d for d in path.split('/') if d] 
        print(dir)
        stack = []
        for d in dir:
            if d == '.':
                continue
            elif d != '..':
                stack.append(d)
            else:
                if  bool(stack):
                    stack.pop()

        return '/' + '/'.join(stack)