def is_valid_deployment_id(deployment_id):
    return (
        deployment_id.startswith("d-")
        and len(deployment_id) == 12
        and deployment_id[2:].isalnum()
        and deployment_id[2:].islower()
    )

def is_valid_status(status):
    
    return status in ("Success", "Fail")

def parse_and_classify(entry):
    try:
        entry = entry.strip()
        if not (entry.startswith("{") and entry.endswith("}")):
            return "Invalid"
        entry = entry[1:-1]  

        parts = entry.split(",")
        data = {}

        for part in parts:
            if ":" not in part:
                return "Invalid"
            key, value = part.split(":", 1)
            key = key.strip().strip('"')
            value = value.strip().strip('"')
            data[key] = value

        if "deployment_id" not in data or "status" not in data:
            return "Invalid"

        if not is_valid_deployment_id(data["deployment_id"]):
            return "Invalid"

        if not is_valid_status(data["status"]):
            return "Invalid"

        return data["status"]
    except:
        return "Invalid"

def evaluate_deployments(deployments):
    success = 0
    fail = 0
    invalid = 0

    for entry in deployments:
        result = parse_and_classify(entry)
        if result == "Success":
            success += 1
        elif result == "Fail":
            fail += 1
        else:
            invalid += 1

    return [success, fail, invalid]

deployments = [
    '{"deployment_id": "d-1234567abc", "status": "Success"}',
    '{"deployment_id": "d-098765fghz", "status": "Fail"}',
    '{"deployment_id": "x-1234567abc", "status": "Fail"}',  # Invalid id
    '{"deployment_id": "d-1234567abc", "status": "Done"}'    # Invalid status
]

print(evaluate_deployments(deployments))