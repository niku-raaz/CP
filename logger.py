
def parse_log(line: str):
    parts=line.split(",")
    if len(parts)!=3:
        return None 
    user,amount,ts=parts
    return {
        "user": user.strip(),
        "amount": int(amount),
        "ts": int(ts)
    }



def test_parse_log():
    #test 1 
    log =parse_log("u1,20,23446")
    assert log["user"]=="u1"
    assert log["amount"]==20
    assert log["ts"]==23446

    #test 2
    log =parse_log("nikk  , 324 , 32552")
    assert log["user"]=="nikk"
    assert log["amount"]== 324
    assert log["ts"]==32552

    #test 3
    log=parse_log("wrong format")
    assert log is None


    print("All tests passed")




def total_spending(logs: list[dict]) -> dict[str,int]:
    usersSpending={}
    for log in logs:
        uId=log["user"]
        amt=log["amount"]
        if uId not in usersSpending:
            usersSpending[uId]=0
        usersSpending[uId]+=amt
    return usersSpending

def test_total_spending():
    #test 1 basic
    logs=[
        parse_log("u1,20,17123000"),
        parse_log("u2,40,17123100"),
        parse_log("u1,10,17124000")
    ]
    
    result=total_spending(logs)
    assert result["u1"] == 30
    assert result["u2"] == 40


    #test 2
    logs=[]
    assert total_spending(logs)== {}

    #test 3
    assert total_spending([parse_log("u3,50,100")]) == {"u3": 50}


    print("Tests passed")


def users_exceeding_limit(totals: dict[str,int],limit: int)-> list[str]:
    usersExceedingLimit=[]
    for user in totals:
        if totals[user]>limit:
            usersExceedingLimit.append(user)
    return usersExceedingLimit

def test_users_exceeding_limit():
    totals={
        "u1":30,
        "u2":40,
        "u3": 10
    }

    #test 1 empty
    assert users_exceeding_limit(totals,100)==[]

    #test 2 
    assert users_exceeding_limit(totals,10) ==["u1","u2"]

    print("Passed tests")


if __name__ == "__main__":
    test_parse_log()
    test_total_spending()
    test_users_exceeding_limit()