import os, ssl, smtplib, sys
from email.message import EmailMessage
from dotenv import load_dotenv
load_dotenv()

def send_email(app_email, app_position):
    email_sender = 'mamko.contact@gmail.com'
    email_password = os.getenv('EMAIL_PWD')
    email_receiver = app_email
    email_server = 'smtp.gmail.com'

    subject = 'Mamko Application Received - {}'.format(app_position)
    body = 'Thank you for your application to the position {}.  We will review it and update you soon. \n\nMamko'.format(app_position)
    em = EmailMessage()
    em['From'] = email_sender
    em['To'] = email_receiver
    em['Subject'] = subject
    em.set_content(body)

    context = ssl.create_default_context()

    with smtplib.SMTP_SSL(email_server, 465, context=context) as smtp:
        smtp.login(email_sender, email_password)
        smtp.sendmail(email_receiver, email_receiver, em.as_string())
    return