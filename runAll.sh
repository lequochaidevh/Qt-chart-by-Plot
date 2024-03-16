#!/bin/bash
#!/bin/sh

cd script/
(trap 'kill 0' SIGINT; ./../app/NetworkPlot & sleep 1.1 )
python3 sendData.py 
exit 0

