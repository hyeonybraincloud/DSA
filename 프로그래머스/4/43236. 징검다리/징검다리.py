def solution(distance, rocks, n):
    # sort the rocks by position
    rocks.sort()
    left, right = 1, distance
    answer = 0

    # binary search for the largest minimum distance
    while left <= right:
        mid = (left + right) // 2
        removed = 0
        prev = 0

        # count how many rocks need to be removed
        for rock in rocks:
            if rock - prev < mid:
                removed += 1
            else:
                prev = rock

        # check the distance from last rock to the end
        if distance - prev < mid:
            removed += 1

        # if too many removals, decrease mid
        if removed > n:
            right = mid - 1
        else:
            # mid is possible, try larger
            answer = mid
            left = mid + 1

    return answer