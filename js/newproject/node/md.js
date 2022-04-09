const {md5} = require('md5js')



const payload = {username:'kalaikabi'}
const myJSON = JSON.stringify(payload)
console.log(md5(myJSON))

const key='secret keyy'
console.log(md5(myJSON+key))