#!/bin/bash

miEmail="'myra@gmail.com'"
miAuten="'myra@gmail.com:TUPASSWORD'"

enviarAfulano="'carlosolivares@id.uff.br'"
archivopdf="carlosolivares.pdf"

curl --url 'smtps://smtp.gmail.com:465' --ssl-reqd \
  --mail-from ${archivopdf} --mail-rcpt ${enviarAfulano} \
    --upload-file ${archivopdf} --user ${miAuten} --insecure


#  --mail-from 'carlosolivares@id.uff.br' --mail-rcpt 'alfaceor@gmail.com' \
