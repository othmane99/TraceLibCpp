# TraceLibCpp

To test the Universal Trace Library with TCP and File Channels, follow these steps:

/1\ Build the Project: Compile the source code using CMake. Navigate to the project directory and run the following commands:
---
mkdir build
cd build
cmake ..
make
---
/2\ Run the Server: Start the server application by running the generated executable. This will initialize the server to listen for incoming TCP connections.
---
./server
---

/3\ Run the Client: Launch the client application, which will connect to the server and send log events. You can customize the events in the client code according to your testing requirements.
---
./client
---

/4\ Check Log Files: 		Verify that log events are being recorded in the designated log files. You should observe log entries in both the client's log file (client_log.txt) and any output from the server application.

/5\ Monitor TCP Traffic: 	If testing the TCP Channel, use network monitoring tools to observe TCP traffic between the client and server. This will confirm that log events are being transmitted over the network.

By following these steps, you can effectively test the functionality of the Universal Trace Library with both TCP and File Channels, ensuring proper logging and communication between client and server components.
