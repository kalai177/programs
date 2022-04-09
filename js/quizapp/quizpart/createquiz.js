import{quizdata} from "../models/questions.js"
import { userdata } from "../models/users.js";
import cookieParser from "cookie-parser";
import dotenv from "dotenv";
import bcrypt from "bcryptjs";
dotenv.config();
const quizauthorization = (req, res, next) => {
  const token = req.cookies.access_token;
  if (!token) {
    return res.sendStatus(403);
  }
  try {
    const data = jwt.verify(token, SECRET);
    if (req.staffname === data.username) return next();
  } catch {
    res.sendStatus(403);
  }
};
const createtest = async (req, res) => {
  const { staffname, subject, topic, testid, N, quiz } = req.body;
  const quizcreator = await userdata.findOne(staffname).lean();
  if (!quizcreator) {
    return res.json({
      status: "error",
      error: "You are not permitted to create quiz",
    });
  }

  try {
    const data = await quizdata.create({
      staffname,
      subject,
      topic,
      testid,
      N,
      quiz: [
        quiz.forEach((ele) => {
          ele.question,
            ele.options.forEach((ele2) => {
              ele2;
            }),
            ele.answer,
            ele.description;
        }),
      ],
    });
    console.log(data);
    return res.json({ status: "error" });
  } catch (error) {
    console.log(error);
    return res.json({ status: "error" });
  }
};

export { quizauthorization, createtest };
