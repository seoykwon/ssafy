const express = require("express");

const app = express();
const PORT = 8080;
const axios = require("axios");
const dotenv = require("dotenv");
const fs = require("fs");
dotenv.config();

// cors setting for frontend
const cors = require("cors");

const morgan = require("morgan");
app.use(cors());
app.use(morgan("dev"));
app.use(express.json());

const url = "https://openapi.naver.com/v1/datalab/search";
app.get("/", async (req, res) => {
  try {
    return res.json({
      test: true,
    });
  } catch (error) {
    return res.json({
      test: false,
    });
  }
});

app.post("/data", async (req, res) => {
  try {
    const {} = req.body;

    const request_body = {
      //   startDate: "2017-01-01",
      //   endDate: "2017-04-30",
      //   timeUnit: "month",
      //   keywordGroups: [
      //     {
      //       groupName: "한글",
      //       keywords: ["한글", "korean"],
      //     },
      //     {
      //       groupName: "영어",
      //       keywords: ["영어", "english"],
      //     },
      //   ],
      startDate: req.body.startDate,
      endDate: req.body.endDate,
      timeUnit: req.body.timeUnit,
      device: req.body.device === "all" ? "" : req.body.device,
      gender: req.body.gender === "all" ? "" : req.body.gender,
      keywordGroups: req.body.keywordGroups,
    };

    // console.log(process.env.CLIENT_ID, process.env.CLIENT_SERVER);
    const headers = {
      "X-Naver-Client-Id": process.env.CLIENT_ID,
      "X-Naver-Client-Secret": process.env.CLIENT_SECRET,
      "Content-Type": "application/json",
    };

    // axios.post(주소, 요청을 넣을 바디, {옵션})
    const response = await axios.post(url, request_body, {
      headers: headers,
      // headers
    });
    // console.log(response);

    fs.writeFile(
      "./uploads/chart.json",
      JSON.stringify(response.data.results),
      (error) => {
        if (error) {
          throw error;
        }
      }
    );

    return res.json(response.data.results);
  } catch (error) {
    console.log(error);
    return res.json({
      test: false,
    });
  }
});

app.get("/data", async (req, res) => {
  try {
    res.set("Content-Type", "application/json; charset=utf-8");

    const tempFile = fs.createReadStream("uploads/chart.json");
    return tempFile.pipe(res);
  } catch (error) {
    return res.json({
      test: false,
    });
  }
});

app.delete("/data", (req, res) => {
  try {
    fs.unlink("uploads/chart.json", (error) => {
      if (error) {
        return res.json(error);
      }
    });
    return res.json({
      delete: true,
    });
  } catch (error) {
    console.log(error);
    return res.json(error);
  }
});

app.listen(PORT, () => console.log(`${PORT} 서버 기동중`));
