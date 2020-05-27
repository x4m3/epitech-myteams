async function send(socket: Deno.Conn, message: string) {
    let encoder = new TextEncoder();
    let to_send = encoder.encode(message + '\n');

    console.log(`message to server: ${message}`);
    await socket.write(to_send);
}

async function receive(socket: Deno.Conn) {
    let decoder = new TextDecoder();
    let buffer = new Uint8Array(1024);
    let message: string;

    await socket.read(buffer);
    message = decoder.decode(buffer);

    console.log("message from server:");
    console.log("---");
    console.log(message);
    console.log("---");
}

async function main() {

    let inputs: Array<string> = [`/login "phil"`];
    let socket = await Deno.connect({ port: 8080 });

    for (let i = 0; i < inputs.length; i++) {
        // read
        await receive(socket);

        // write
        await send(socket, inputs[i]);

        console.log();
    }

    // last message from server
    await receive(socket);

    // bye bye
    socket.close();
}

main();
