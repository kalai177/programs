const http=require('http')
const server=http.createServer((req,res)=>{
   if(req.url==='/') res.end('welcome to home page')
   if(req.url==='/about') res.end(' these and all about our abouts')
   res.end(
       `
       <h1> oopsss!!</h1>
       <h2> there is no reasults for ur search</h2>
       <p>try other</p>
       <a href='/about'>back about</a>
       
       `
   )

})
server.listen(5000)