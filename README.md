# Minitalk

This project transfers data between two files running locally using Unix signals.

<br>

## Details

- **First the server file is run**. The server file writes a pid and waits for a signal.
- Open a different terminal and run the client file. **enter the pid** as the first argument and then write the data to be transferred.
-  When the run key is pressed, **the data written in the client appears as output on the server**.
