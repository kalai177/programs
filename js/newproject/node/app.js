const express = require('express')
const kala= express()
const port = 3000

kala.get('/', (req, res) => {
  res.send('hi')
})
kala.get('/entrace/login',(req,res)=>{
  res.send('plz login')
})
kala.get('/entrace/register',(req,res)=>{
  res.send('plz register')
})
console.log('port listening')
kala.listen(port)