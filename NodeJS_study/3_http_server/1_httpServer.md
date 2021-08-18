```jsx
const http = require('http');
const fs = require('fs').promises;

http.createServer(async (req, res) => {
    try {
        const data = await fs.readFile('./server.html');
        res.writeHead(200, {'Content-Type':'text/html; charest=utf-8'});
        res.end(data);
    } catch(err) {
        console.error(err);
        res.writeHead(500, {'Content-Type':'text/plain; charset=utf-8'});
        res.end(err.message);
    }
    
}).listen(8080, () => {
    console.log('port 8080 is ready');
});
```

- createServer 메서드 뒤에 listen 메서드를 붙이고 클라이언트에 공개할 포트 번호와 포트 연결 후 실행될 콜백 함수를 넣는다.
- res.writeHead는 응답에 대한 정보를 기록하는 메서드이다.
- res.write 메서드의 첫 번째 인수는 클라이언트로 보낼 데이터이다.
- fs.readFile은 html 파일을 읽음