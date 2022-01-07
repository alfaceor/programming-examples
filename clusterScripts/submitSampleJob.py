import urllib2		# network managment.
import zipfile		# file zip managment.
import simplejson	# json managment.
import os			# operate system.
import shutil		# High-level file operations.

# Se descarga el job
try:
	os.remove('clusterJob.zip')		# Se elimina cualquier archivo anterior.
except:
	pass

clusterJob = urllib2.urlopen('http://www.upch.edu.pe/WSmods/getJob/job1.zip')
localFile = open('clusterJob.zip','w')
localFile.write(clusterJob.read())
localFile.close()

# Se Lee el zip descargado
archivo_zip = zipfile.ZipFile('clusterJob.zip', 'r')

# se extrae la metainfo
for info in archivo_zip.infolist():
	fname = info.filename
	if fname.endswith(".inf"):
		fnamemetainf = fname

	if fname.endswith(".jpg"):
		fnamephoto = fname

# se carga la metadata 
metainf = simplejson.loads(archivo_zip.read(fnamemetainf))

# se carga la foto jpg, jpg, jpeg
try:
	shutil.rmtree(metainf['id'])		# elimina el directorio completo.
except:
	pass
os.makedirs(metainf['id'])
photofile = open(''+metainf['id']+'/'+metainf['id']+'.jpg','w')
photofile.write(archivo_zip.read(fnamephoto))
photofile.close()
os.remove('clusterjob.zip')

# os.exec(qsub -cwd -v RMODS_IMAGE_FILE=P1010018.JPG -V submitJobRMODS.q)

# Se envia el job con el qsub script.
# Con esta linea se va a poder enviar el json.
# curl -F 'username=alfaceor' http://localhost/pruebasWebServices/libcurltest/target.php


