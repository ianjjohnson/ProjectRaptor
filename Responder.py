#!/usr/bin/env python

import smtplib
import time
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import os

def buildMessage(sender, recipient, subject, body):
	return """\
	From: %s
	To: %s
	Subject: %s
	\n
	%s
	""" % (sender, recipient, subject, body)

def sendMessage(body):
	body = body + ""
		
	message = buildMessage("ianlinuxserver@gmail.com", "3038153710@mms.att.net", "New System!", "This is a test message from the new texting system")

	mailServer = smtplib.SMTP("smtp.gmail.com:587")
	mailServer.starttls()
	mailServer.login("ianlinuxserver@gmail.com", "LinuxMint2015!")

	
	for i in range(5):
		mailServer.sendmail("ianlinuxserver@gmail.com", "3038153710@mms.att.net", body)

	mailServer.quit()
	print("Sent Text:" + body)

sendMessage("Swiggity Swiggity Swag on Rye!")
	
