import urllib2		# network managment.
import zipfile		# file zip managment.
import simplejson	# json managment.
import os		# operate system.
import shutil		# High-level file operations.

tempFileZip='clusterGridJob.zip'

# Se descarga el job
try:
	os.remove(tempFileZip)		# Se elimina cualquier archivo anterior.
except:
	pass

clusterJob = urllib2.urlopen('http://www.upch.edu.pe/wsmods/getGridJob.php?EndpointID=test')
localFile = open(tempFileZip,'w')
localFile.write(clusterJob.read())
localFile.close()

# Se Lee el zip descargado
archivo_zip = zipfile.ZipFile(tempFileZip, 'r')

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
os.remove(tempFileZip)

# os.exec(qsub -cwd -v RMODS_IMAGE_FILE=P1010018.JPG -V submitJobRMODS.q)


