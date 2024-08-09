// 지도 관련 js 코드

  let mapContainer = document.querySelector('#map');
  let mapOption = { 
        center: new kakao.maps.LatLng(37.50136, 127.0396), // 지도의 중심좌표
        level: 3, // 지도의 확대 레벨
        mapTypeId: kakao.maps.MapTypeId.ROADMAP // 지도종류
    };

let map = new kakao.maps.Map(mapContainer, mapOption); 

// 빌딩이미지(싸피건물)
 let imageSrc = "./img/building.png";
 let imageSize = new kakao.maps.Size(64,69);
 let imageOtion = {offset : new kakao.maps.Point(32, 60)}

 let initialMarkerImage = new kakao.maps.MarkerImage(
  imageSrc,
  imageSize,
  imageOtion
 );

 let initialMarkerPosition = new kakao.maps.LatLng(37.50136, 127.0396);


 let initialMarKer = new kakao.maps.Marker({
  image : initialMarkerImage,
  position : initialMarkerPosition
 });

 initialMarKer.setMap(map);


 let initialInfoWindow = new kakao.maps.InfoWindow({
  content: `<div style="color: gray; font-size:10px; padding:5px">역삼 멀티 캠퍼스에서 출발</div>`
 });
 

 initialInfoWindow.open(map, initialMarKer);

let ps = new kakao.maps.services.Places();

let markers = [];

let infowindow = new kakao.maps.InfoWindow();
let polyline = new kakao.maps.Polyline();

const searchFunction = function(event) {

  if (event.type === 'keyup' && event.key !== 'Enter') return;
  infowindow.close();        
 let keyword = document.querySelector('#search-input').value;
  if (!keyword.trim()) {
  alert('키워드를입력해주세요!');
  return;
  }

 ps.keywordSearch(keyword, placesSearchCB); 
 infowindow.setMap(null);
  polyline.setMap(null);
  };

 document.getElementById('search-button').addEventListener('click', searchFunction);

 document.getElementById('search-input').addEventListener('keyup', searchFunction);

 function placesSearchCB(data, status, pagination) {
  if (status === kakao.maps.services.Status.OK) {

 displayPlaces(data);
  } else {
  alert('검색 결과가 없습니다.');
  }
  }

 function displayPlaces(places) {
  let listEl = document.querySelector('.search-results');
  listEl.innerHTML = '';

 removeMarkers();
  for (let i = 0; i < places.length; i++) {
  let itemEl = document.createElement('div');
  itemEl.className = 'item';
  itemEl.innerHTML = `
  <div class="info">
  <b>${places[i].place_name}</b>
  <br/><br/>
  <span>${places[i].road_address_name}</span>
  <span class="tel">${places[i].phone}</span>
  </div>
  `;
  itemEl.addEventListener('click', function() {
      infowindow.close();

    let centerPosition = new kakao.maps.LatLng(places[i].y, places[i].x);

    map.setCenter(centerPosition);
    // startNavigation(places[i]);
    infowindow = new kakao.maps.InfoWindow({
    content : `<div style="padding:5px; color:gray;font-size:1.1vw;">${places[i].
    place_name}</div>` 
    });
    infowindow.open(map, marker);
    
    getCarDirection(initialMarkerPosition, centerPosition);
 });
 listEl.appendChild(itemEl);
 
// addMarker(new kakao.maps.LatLng(places[i].y, places[i].x));
 let marker = new kakao.maps.Marker({
 position: new kakao.maps.LatLng(places[i].y, places[i].x)
 });
 marker.setMap(map);
 markers.push(marker);
 kakao.maps.event.addListener(marker, 'click', function() {
    infowindow.close();
    
    let centerPosition = new kakao.maps.LatLng(places[i].y, places[i].x);
    map.setCenter(centerPosition);                
    infowindow = new kakao.maps.InfoWindow({
    content : `<div style="padding:5px; color:gray;font-size:1.1vw;">${places[i].
    place_name}</div>` 
    });
    infowindow.open(map, marker);
    getCarDirection(initialMarkerPosition, centerPosition);
 });
 }
 }
 
function removeMarkers() {
 for (let i = 0; i < markers.length; i++) {
 markers[i].setMap(null);
 }   
markers = [];
 }

// map.js
async function getCarDirection(startPosition, destinationPosition) {

  try
  {
    REST_API_KEY;
  }
  catch(e)
  { 
    alert("API키가 없습니다.");
  }

  const url = "https://apis-navi.kakaomobility.com/v1/directions";

  const origin = `${startPosition.La},${startPosition.Ma}`;
  const destination = `${destinationPosition.La},${destinationPosition.Ma}`;

  const headers = {
  Authorization: `KakaoAK ${REST_API_KEY}`,
  "Content-Type": "application/json",
  };

  const queryParams = new URLSearchParams({
    origin: origin,
    destination: destination,
  });
  const requestUrl = `${url}?${queryParams}`; 
  try {
    const response = await axios.get(requestUrl, { headers: headers });
    if (response.status !== 200) {
      throw new Error(`HTTP error! Status: ${response.status}`);
    }
    const data = response.data;
    console.log("data = ", data);

    const linePath = [];

    data.routes[0].sections[0].roads.forEach((router) => {
      router.vertexes.forEach((vertex, index) => {
        if (index % 2 === 0) {
          linePath.push(
            new kakao.maps.LatLng(
              router.vertexes[index + 1],
              router.vertexes[index]
            )
          );
        }
      });
    });

    polyline.setMap(null);

    polyline = new kakao.maps.Polyline({
      path: linePath,
      strokeWeight: 5,
      strokeColor: "#000000",
      strokeOpacity: 0.7,
      strokeStyle: "solid",
    });

    polyline.setMap(null);

    polyline = new kakao.maps.Polyline({
      path: linePath,
      strokeWeight: 5,
      strokeColor: "#000000",
      strokeOpacity: 0.7,
      strokeStyle: "solid",
    });

    polyline.setMap(map);

    let initialInfowindowBounds = new kakao.maps.LatLng(37.50936, 127.0396);
    let bounds = new kakao.maps.LatLngBounds(
      initialInfoWindowBounds,
      destinationPosition
    );
    bounds.extend(initialMarkerPosition);

    map.setBounds(bounds);

  } catch (error) {
    console.error("Error:", error);
  }
  }

