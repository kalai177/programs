import Mongoose from "mongoose";
const userschema = new Mongoose.Schema({
  staffname: { type: String, required: true },
  subject: { type: String, required: true },
  topic: { type: String, required: true },
  testid: { type: String, required: true, unique: true },
  N: { type: Number, required: true },
  quiz: [
    {
      question: String,
      options: [{ type: String }],
      anskey: String,
      description: String,
    },
  ],
});

const quizdata = Mongoose.model("quiz", userschema);
export { quizdata };
