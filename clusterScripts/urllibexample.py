import urllib.request;	# Manejo de url
import zipfile	# Manejo de archivos zip

urladdress="http://www.upch.edu.pe/wsmods/getJob/job1.zip"
urllib.request.urlretrieve(url, "job1.zip")
# zfilename="prueba.zip"
# zfile = zipfile.ZipFile( zfilename, "r" )
# params = urllib.urlencode({'spam': 1, 'eggs': 2, 'bacon': 0})


# f = urllib.urlopen(urladdress)
# print f.read()

# f = urllib.urlopen("http://www.musi-cal.com/cgi-bin/query?%s" % params)
# f = urllib.urlopen("http://www.google.com/#%s" % params)

# http://www.google.com/#hl=en&source=hp&q=hola&aq=f&aqi=g5g-s1g2g-s1g1&oq=&fp=292ac4760832f3c4

# print f.read()

