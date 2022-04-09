import Mongoose from "mongoose";
const userschema = new Mongoose.Schema({
  username: { type: String, require: true, unique: true },
  password: { type: String, require: true },
  role: { type: String, require: true },

});

const userdata = Mongoose.model("Users", userschema);
export {userdata}