import dotenv from "dotenv";
dotenv.config();
const secret = process.env.SECRET;
import cookieParser from "cookie-parser";
import jwt from "jsonwebtoken";
import  {userdata} from "../models/users.js";
import bcrypt from "bcryptjs";
const loginadmin = async (req, res) => {
  const { username, password, role } = req.body;
  const user = await userdata.findOne({ username }).lean();
  if (!user) {
    return res.json({ status: "error", error: "user not exist" });
  }
  if (user.role !== role) {
    return res.json({
      status: "error",
      error: "permision denied, u r not an admin",
    });
  }

  try {
    await bcrypt.compare(password, user.password);
    const token = jwt.sign(
      {
        id: user._id,
        username: user.username,
        role: user.role,
      },
      secret
    );

    return res
      .cookie("access_token", token, {
        httpOnly: false,
        secure: true,
      })
      .json({ status: "ok" });
  } catch (error) {
    console.log(error)
    return res.json({ status: "error", error: "invalid username or password" });
  }
};

const loginstaff = async (req, res) => {
  const { username, password, role } = req.body;
  const user = await userdata.findOne({ username }).lean();
  if (!user) {
    return res.json({ status: "error", error: "user not exist" });
  }
  if (user.role !== role) {
    return res.json({
      status: "error",
      error: "permision denied, u r not an staff",
    });
  }

  try {
    await bcrypt.compare(password, user.password);
    const token = jwt.sign(
      {
        id: user._id,
        username: user.username,
        role: user.role,
      },
      secret
    );
     console.log("verified")
    return res
      .cookie("access_token", token, {
        httpOnly: false,
        secure: true,
      })
      .json({ status: "ok" });
  } catch (error) {
    console.log(error)
    return res.json({ status: "error", error: "invalid username or password" });
  }
};

const loginstudent = async (req, res) => {
  const { username, password, role } = req.body;
  const user = await userdata.findOne({ username }).lean();
  if (!user) {
    return res.json({ status: "error", error: "user not exist" });
  }
  if (user.role !== role) {
    return res.json({
      status: "error",
      error: "permision denied, u r not an student",
    });
  }

  try {
    await bcrypt.compare(password, user.password);
    const token = jwt.sign(
      {
        id: user._id,
        username: user.username,
        role: user.role,
      },
      secret
    );

    return res
      .cookie("access_token", token, {
        httpOnly: false,
        secure: true,
      })
      .json({ status: "ok" });
  } catch (error) {
    return res.json({ status: "error", error: "invalid username or password" });
  }
};

export{ loginadmin, loginstaff, loginstudent };
