# Mordyk Alex

# Description:
Server application to search file on remote HOST.<br/>
- client has functionality to search file by server request.<br/>
- server will request search by file name.<br/>
- client has to replay with processing each 500ms of searching<br/>
- client has to reply with success or failure.<br/>
- success replay has to include full path to the file.<br/>

# Project dependencies
- Linux, g++, Make, nc etc.<br/>

## How to apply these changes:

1. Clone all repo in your project folder.<br/>
2. Run the build:<br/>
make -j8<br/>
3. Run the server using commands.<br/>
./serverApp<br/>

Default server ip: 127.0.0.1, port: 7828<br/>

![Image alt](https://github.com/kurtwalkir/glcpp/tree/master/task1/screen/server.png)<br/>
![Image alt](https://github.com/kurtwalkir/glcpp/tree/master/task1/screen/server.png)

