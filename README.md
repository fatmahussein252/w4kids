# w4kids
This repo contains my implementation in C of a Non-blocking wait function as an alternative to the linux wait system call.

The w4kids function handles all its terminated children and print the PID, exit status, and the reason for termination (signal or normal exit), it also makes sure non of the dead children became a zombie process.

## output

![image](https://github.com/user-attachments/assets/063152f1-c3d0-4b1e-8f78-e541fbaef47e)
