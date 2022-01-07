#!/bin/bash

case "$1" in
        start)
            echo "start bitch!"
            ;;
         
        stop)
            echo "stop motherfucker"
            ;;
         
        status)
            echo "what is your status"
            ;;
        restart)
            stop
            start
            ;;
        condrestart)
            if test "x`pidof anacron`" != x; then
                stop
                start
            fi
            ;;
         
        *)
            echo $"Usage: $0 {start|stop|restart|condrestart|status}"
            exit 1
 
esac

