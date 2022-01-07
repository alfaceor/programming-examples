#!/usr/bin/python

print "Oh shit"

from bs4 import BeautifulSoup

html_doc = """
<html><head><title>The Dormouse's story</title></head>
<body>
<p class="title"><b>The Dormouse's story</b></p>

<p class="story">Once upon a time there were three little sisters; and their names were
<a href="http://example.com/elsie" class="sister" id="link1">Elsie</a>,
<a href="http://example.com/lacie" class="sister" id="link2">Lacie</a> and
<a href="http://example.com/tillie" class="sister" id="link3">Tillie</a>;
and they lived at the bottom of a well.</p>

<p class="story">...</p>
"""

html_doc = 
soup = BeautifulSoup(html_doc, 'html.parser')

#print soup.prettify()

print soup


import urllib.request
from bs4 import BeautifulSoup


def extract_fasta(url):
    """ Extract fasta information from the typical IMGT format
    """
    print(url)
    result_dct = {}
    headers = {}
    with urllib.request.urlopen(url) as response:
        html = response.read()
        soup = BeautifulSoup(html, 'html.parser')
        result = soup.find_all('pre')[1].text
        name = seq = header = ""
        for line in result.split("\n"):
            if line.strip() != "":
                if line[0] == ">":
                    if name != "":
                        result_dct[name] = seq
                        headers[name] = header
                    header = line[1:].strip()
                    seq = ""
                    name = line.split("|")[1]
                else:
                    seq += line.strip().upper()
        result_dct[name] = seq
        headers[name] = header
    return result_dct, headers




