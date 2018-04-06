import socket
import re
import time

"""Downloading an image using sockets, GET request and Regular expressions """

class DorHTTP:

    def __init__(self, host, url):       #contructor for the host and the url to scrape
        self.host = host
        self.url = url

    def get_it(self):          #using a GET to get the source code and saving as txt file

        mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        mysock.connect((self.host, 80))
        cmd = 'GET ' + self.url + ' HTTP/1.0\r\n\r\n'
        new_cmd = cmd.encode()
        mysock.send(new_cmd)

        while True:
            data = mysock.recv(20)
            if (len(data) < 1):
                break
            print(data.decode(), end='')
            new_file = open('sc.txt', 'a')
            new_file.write(str(data))
            new_file.close()

        mysock.close()

    def get_img(self):      #using regex to fing the jpg url

        DorHTTP.get_it(self)
        global img_url

        regex = re.compile(r'href=[\'"]?([^\'" >]+jpg)')
        with open('sc.txt') as f:
            for line in f:
                imgs = regex.findall(line)
            img_url = self.url + '/' + str(imgs[0])

    def download_img(self):     #downloading the image using socket

        DorHTTP.get_img(self)

        mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        mysock.connect((self.host, 80))
        img_url_cmd = ('GET ' + img_url + ' HTTP/1.0\r\n\r\n')
        img_url_cmd_byts = img_url_cmd.encode()
        mysock.sendall(img_url_cmd_byts)
        count = 0
        picture = b""

        while True:
            data = mysock.recv(5120)
            if (len(data) < 1): break
            time.sleep(0.25)
            count = count + len(data)
            print(len(data), count)
            picture = picture + data

        mysock.close()

        pos = picture.find(b"\r\n\r\n")
        picture = picture[pos + 4:]
        fhand = open("stuff.jpg", "wb")         #saving the image as stuff
        fhand.write(picture)
        fhand.close()

test1 = DorHTTP('data.pr4e.org', 'http://data.pr4e.org')
test1.download_img()




