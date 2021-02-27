"""CLI tool to commit source code to GitHub repository"""
#!/usr/bin/env python3

import argparse
import base64
import json
import os
import subprocess
import sys

import requests


def parse_option():
    parser = argparse.ArgumentParser()
    parser.add_argument("filename", type=str, help="filename to upload")
    return parser.parse_args()


def get_git_config():
    def get_stdout(command: list):
        res = subprocess.check_output(command)
        return res.decode("utf-8").rstrip()

    username = get_stdout(["git", "config", "user.name"])
    email = get_stdout(["git", "config", "user.email"])
    return username, email


def get_base64_content(filename: str):
    with open(filename) as f:
        data = f.read().encode()
        return base64.b64encode(data).decode("utf-8")


def main():
    arg = parse_option()
    username, email = get_git_config()
    repository = "atcoder-archives"
    contest = input("contest: ")
    problem = input("problem: ")

    url = f"https://api.github.com/repos/{username}/{repository}/contents/{contest}/{problem}.cpp"

    auth = ("my_client_id", os.environ["GITHUB_CLIENT_ID"])

    body = {
        "message": f"Create {contest}/{problem}.cpp",
        "committer": {"name": username, "email": email},
        "content": get_base64_content(arg.filename),
    }

    res = requests.get(url, auth=auth)
    data = res.json()
    if data.get("content"):
        print(f"File already exists: {contest}/{problem}.cpp")
        y_n = input("Do you continue to upload? [y/n]: ")
        if y_n != "y":
            sys.exit(1)
        body["sha"] = data["sha"]
        body["message"] = f"Update {contest}/{problem}.cpp"

    res = requests.put(url, auth=auth, data=json.dumps(body))
    res.raise_for_status()


if __name__ == "__main__":
    try:
        main()
        print("Successfully uploaded")
    except KeyboardInterrupt:
        print()
