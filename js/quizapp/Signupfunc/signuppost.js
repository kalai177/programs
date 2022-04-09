import  {userdata} from "../models/users.js";
import bcrypt from "bcryptjs";
const Admin = async (req, res) => {
  const { username, password } = req.body;
  if (typeof username !== "string" || !username) {
    return res.json({ status: "error", error: "invalid username" });
  }

  if (!password || typeof password !== "string") {
    return res.json({ status: "error", error: "invalid password" });
  }

  if (password.length < 5) {
    return res.json({ status: "error", error: "password is too small" });
  }

  const passcode = await bcrypt.hash(password, 10);
  const role = "admin";
  try {
    const result = userdata.create({
      username,
      passcode,
      role,
    });
    console.log("usercreated succesfully", result);
  } catch (error) {
    if (error.code === 11000) {
      return res.json({ status: "error", error: "Username already in use" });
    }
    throw error;
  }
  return res.json({ status: "ok" });
};

const Staff = async (req, res) => {
  const { username, password } = req.body;
  if (typeof username !== "string" || !username) {
    return res.json({ status: "error", error: "invalid username" });
  }

  if (!password || typeof password !== "string") {
    return res.json({ status: "error", error: "invalid password" });
  }

  if (password.length < 5) {
    return res.json({ status: "error", error: "password is too small" });
  }

  const passcode = await bcrypt.hash(password, 10);

  const role = "staff";

  try {
    const result = userdata.create({
      username,
      passcode,
      role,
    });
    console.log("usercreated succesfully", result);
  } catch (error) {
    if (error.code === 11000) {
      return res.json({ status: "error", error: "Username already in use" });
    }
    throw error;
  }
  return res.json({ status: "ok" });
};

const Student = async (req, res) => {
  const { username, password } = req.body;
  if (typeof username !== "string" || !username) {
    return res.json({ status: "error", error: "invalid username" });
  }

  if (!password || typeof password !== "string") {
    return res.json({ status: "error", error: "invalid password" });
  }

  if (password.length < 5) {
    return res.json({ status: "error", error: "password is too small" });
  }

  const passcode = await bcrypt.hash(password, 10);

  const role = "student";

  try {
    const result = userdata.create({
      username,
      passcode,
      role,
    });
    console.log("usercreated succesfully", result);
  } catch (error) {
    if (error.code === 11000) {
      return res.json({ status: "error", error: "Username already in use" });
    }
    throw error;
  }
  return res.json({ status: "ok" });
};

export { Admin, Staff, Student };
