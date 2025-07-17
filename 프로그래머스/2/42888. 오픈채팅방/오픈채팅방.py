def solution(record):
    uid_to_nick = {}
    for r in record:
        cmd, uid, *rest = r.split()
        if cmd in ("Enter", "Change"):
            uid_to_nick[uid] = rest[0]

    answer = []
    for r in record:
        cmd, uid, *_ = r.split()
        if cmd == "Enter":
            answer.append(f"{uid_to_nick[uid]}님이 들어왔습니다.")
        elif cmd == "Leave":
            answer.append(f"{uid_to_nick[uid]}님이 나갔습니다.")

    return answer
