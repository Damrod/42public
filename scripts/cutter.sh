#!/bin/bash
DIR="/home/alvaro/Documents/rev-engineering"
LUID=$(id -u)
LGID=$(id -g)
XSOCK=/tmp/.X11-unix
XAUTH=$(mktemp /tmp/r2cutter_tmp.XXX.xauth)
IMAGE_NAME="radareorg/cutter"
CONTAINER_NAME=cutter
VERSION=latest
if [[ -e $1 ]]; then
	MOUNTFLAGS="-v $(pwd)/${1}:/home/r2/$(basename ${1}):ro"
	RUNFLAGS="/home/r2/$(basename ${1})"
fi
xauth nlist ${DISPLAY} | sed -e 's/^..../ffff/' | xauth -f ${XAUTH} nmerge -
chmod 644 ${XAUTH}
echo "-v ${XSOCK}:${XSOCK}:ro -v ${XAUTH}:${XAUTH}"
docker run \
	   --rm \
	   -it \
	   --name ${CONTAINER_NAME} \
	   --cap-add=SYS_PTRACE \
	   -e DISPLAY=${DISPLAY} \
	   -e XAUTHORITY=${XAUTH} \
	   -e LOCAL_USER_ID=${LUID} \
	   -e LOCAL_GROUP_ID=${LGID} \
	   -v ${XSOCK}:${XSOCK}:ro \
	   -v ${XAUTH}:${XAUTH} \
	   ${MOUNTFLAGS} \
	   -v ${DIR}:/home/r2/sharedFolder \
	   -v ${HOME}/.config/radare2/.radare2rc:/home/r2/.radare2rc \
	   -v ${HOME}/.config/radare2/:/home/r2/.config/radare2 \
	   ${IMAGE_NAME}:${VERSION} ${RUNFLAGS} && \
rm ${XAUTH}
