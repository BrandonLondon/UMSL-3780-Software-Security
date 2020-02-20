#!/usr/bin/python

import sys
import itertools
import string
from hashlib import sha256
import time


class User:
	def __init__(self, username, hashedPass, salt):
		self.username = username
		self.hashedPass = hashedPass
		self.salt = salt

def get_sha256(password):
	hashedPass = sha256(password).hexdigest()
	return(hashedPass)

def get_hashes(passFile):
	hashes = []
	with open(passFile) as file:
		for line in file:
			if(passFile == 'pass2'):
				currentLine = line.split(":")
				username = currentLine[0].rstrip()
				hashedPass = currentLine[1].rstrip()
				hashes.append(User(username, hashedPass, ""))
			if(passFile == 'pass3'):	
				currentLine = line.split(":")
				username = currentLine[0].rstrip()
				hashedPass = currentLine[1].rstrip()
				salt = currentLine[2].rstrip()
				hashes.append(User(username, hashedPass, salt))
		return hashes	


def guess_password(passFile):	
	hashes = get_hashes(passFile)
	chars = string.ascii_lowercase
	attempts = 0
	start = time.time()
	for password_length in range(3, 8):
		for guess in itertools.product(chars, repeat = password_length):
			attempts += 1
			guess = ''.join(guess)
			for i in range(len(hashes)):
				if(passFile == 'pass2'):
					if get_sha256(guess) == hashes[i].hashedPass:
						end = time.time()
						totalTime = end - start
						return 'password for {} is {}. found in {} seconds.'.format(hashes[i].username, guess, round(totalTime, 4))

					print(guess)
				if(passFile == 'pass3'):
					salt = hashes[i].salt
					if get_sha256(guess + salt) == hashes[i].hashedPass:
						end = time.time()
						totalTime = end - start
						return 'password for {} is {}. found in {} seconds.'.format(hashes[i].username, guess, round(totalTime, 4))
					print(guess)

	return 'couldnt crack password'	

def main():
	if len(sys.argv) == 2:
		passFile = sys.argv[1]
		print(guess_password(passFile))
	else:	
		print 'usage: python crack.py <password file>'
	
	

if __name__ == "__main__":
	main()











