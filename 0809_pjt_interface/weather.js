

function getWeather() {
  // 날씨 api 호출 테스트
  // const WEATHER_API_KEY = "키 채우기";
  try{
    WEATHER_API_KEY;
  }catch(e){ alert("날씨 API키가 없습니다.");
  }
  const city = "Seoul,kr";
  const url = `https://api.openweathermap.org/data/2.5/forecast?q=${city}&appid=${WEATHER_API_KEY}&units=metric&lang=kr`;

  axios.get(url).then((response) => {
    const data = response.data;
    const wtitle = document.querySelector('.weather-title');
    const weatherForecastDiv = document.querySelector('.weather-forecast');
    weatherForecastDiv.innerHTML = '';

    // extract weather data for the next 5 days
    const forecastList = data.list.filter((item, index) => index % 8 === 0).slice(0, 5);

    forecastList.forEach(item => {
      const date = new Date(item.dt_txt);
      const options = { weekday: 'long', month: 'long', day: 'numeric'};
      const weatherInfo = `
      <div class="weather-info">
        <h2>${date.toLocaleDateString('ko-KR', options)}</h2>
        <img src="http://openweathermap.org/img/wn/${item.weather[0].icon}.png" alt="${item.weather[0].description}">
        <p>${item.weather[0].description}</p>
        <p>온도: ${item.main.temp_max.toFixed(1)}°C</p>
        <p>습도: ${item.main.humidity}%</p>
        <p>바람: ${item.wind.speed} m/s</p>
      </div>
      `;

      weatherForecastDiv.innerHTML += weatherInfo;

      wtitle.textContent = `hello ${city}`;
    });
  })
  .catch(error => {
    console.error('날씨 정보를 가져오는 중 오류 발생:', error);
    const weatherForecastDiv = document.querySelector('#weather-forecast');
    weatherForecastDiv.innerHTML = '날씨 정보를 가져오는 중 오류 발생';
  });
}

getWeather();
