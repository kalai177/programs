import express from "express";
import path from "path/posix";
const app = express();
import jwt from "jsonwebtoken";
import bcrypt from "bcryptjs";
import Mongoose from "mongoose";
import cookieParser from "cookie-parser";
const port = process.env.PORT || 3000;
import dotenv from "dotenv";
dotenv.config();

import { Admin, Staff, Student } from "./Signupfunc/signuppost.js";

import { loginadmin, loginstaff, loginstudent } from "./Signupfunc/login.js";

import { quizauthorization,createtest } from "./quizpart/createquiz.js";

const url =
  "mongodb+srv://KALAIYARASIL:9e5CJ3&RgF^j^P@cluster0.e7edc.mongodb.net/myFirstDatabase?retryWrites=true&w=majority";

const connectionParams = {
  useNewUrlParser: true,
  useUnifiedTopology: true,
};
Mongoose.connect(url, connectionParams)
  .then(() => {
    console.log("Connected to database ");
  })
  .catch((err) => {
    console.error(`Error connecting to the database. \n${err}`);
  });

app.use(cookieParser());
app.use(express.json());

app.post("/signupadmin", express.json(), Admin);

app.post("/signupstaff", express.json(), Staff);

app.post("/signupstudent", express.json(), Student);

app.post("/signinadmin", express.json(), loginadmin);

app.post("/signinstaff", express.json(), loginstaff);

app.post("/signinstudent", express.json(), loginstudent);

app.post("/quizpost",express.json(),createtest)

app
  .listen(port, function () {
    console.log("success http://localhost:3000/");
  })
  .on("error", function (error) {
    console.log(error);
  });
