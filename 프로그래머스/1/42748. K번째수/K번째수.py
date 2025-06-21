def solution(array, commands):
    result = []
    for command in commands:
        i, j, k = command
        sliced = array[i-1:j]
        sliced.sort()
        result.append(sliced[k-1])
        
    return result