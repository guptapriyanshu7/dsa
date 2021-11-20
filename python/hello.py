# from sys import stdin, stdout
# for i in range(2, 10):
#     print(i, end="")
# print()
# print(5, 4, sep="")
# x, y = list(map(int, stdin.readline().split()))
# n = list(map(int, stdin.readline().split()))
# s = input()
# print(x, y, n, s)
# z = int(input())
# print(type(z))

# print pid of the process
# import os
# print(os.getpid())

# execute fork and print pid
# import os
# pid = os.fork()
# if pid == 0:
#   print("child", pid)
# else:
#   print("parent", pid)

# execute exec and print pid
# import os
# pid = os.fork()
# if pid == 0:
#   os.execv("/bin/ls", ["ls", "-l"])
# else:
#   print("parent", pid)

# a web crawler
# import urllib.request
# import urllib.parse
# import urllib.error
# from bs4 import BeautifulSoup
# import ssl

# # Ignore SSL certificate errors
# ctx = ssl.create_default_context()
# ctx.check_hostname = False
# ctx.verify_mode = ssl.CERT_NONE

# url = input('Enter - ')
# html = urllib.request.urlopen(url, context=ctx).read()
# soup = BeautifulSoup(html, 'html.parser')

# # Retrieve all of the anchor tags
# tags = soup('a')
# for tag in tags:
#     print(tag.get('href', None))

# knapsack problem 0-1
# from sys import stdin
# n, W = list(map(int, stdin.readline().split()))
# wt = list(map(int, stdin.readline().split()))
# val = list(map(int, stdin.readline().split()))
# memo = [[0] * (W + 1) for _ in range(n + 1)]
# for i in range(1, n + 1):
#     for j in range(1, W + 1):
#         if wt[i - 1] <= j:
#             memo[i][j] = max(memo[i - 1][j], val[i - 1] +
#                              memo[i - 1][j - wt[i - 1]])
#         else:
#             memo[i][j] = memo[i - 1][j]
# print(memo[n][W])

# connect to mongodb
# import pymongo
# myclient = pymongo.MongoClient("mongodb://localhost:27017/")
# mydb = myclient["graphql"]
# mycol = mydb["users"]
# x = mycol.find_one()
# print(x)
