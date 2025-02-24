<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>MiniTalk README</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            background-color: #f4f4f4;
            padding: 20px;
        }
        .container {
            max-width: 800px;
            background: white;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
        }
        code {
            background: #eee;
            padding: 3px;
            border-radius: 5px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>MiniTalk 🗨️</h1>
        <p>A simple communication program between a server and a client using UNIX signals (SIGUSR1 & SIGUSR2). 🚀</p>
        <h2>How It Works ⚙️</h2>
        <ul>
            <li>The <strong>server</strong> waits for messages and prints received characters.</li>
            <li>The <strong>client</strong> sends a message, bit by bit, using signals.</li>
        </ul>
        <h2>Installation & Usage 📜</h2>
        <ol>
            <li><strong>Compile the programs:</strong></li>
            <pre><code>make</code></pre>
            <li><strong>Run the server:</strong></li>
            <pre><code>./server</code></pre>
            <p>This will print the server's PID (Process ID).</p>
            <li><strong>Send a message with the client:</strong></li>
            <pre><code>./client &lt;server_pid&gt; "Hello, world!"</code></pre>
        </ol>
        <h2>Features ✨</h2>
        <ul>
            <li>Sends messages from client to server using signals.</li>
            <li>Handles signals safely.</li>
            <li>Notifies when the message is fully received.</li>
        </ul>
        <h2>Notes 📝</h2>
        <ul>
            <li>Ensure to use the correct server PID.</li>
            <li>Works only on UNIX-based systems.</li>
        </ul>
        <p>Happy coding! 💻🚀</p>
    </div>
</body>
</html>
