import { initializeApp } from "https://www.gstatic.com/firebasejs/10.12.2/firebase-app.js";
import { getFirestore } from "https://www.gstatic.com/firebasejs/10.12.2/firebase-firestore.js";

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyA7wmd2L-6Lxgff5TWrt7JOUjfZrMy-2OQ",
  authDomain: "my-project-178f8.firebaseapp.com",
  projectId: "my-project-178f8",
  storageBucket: "my-project-178f8.appspot.com",
  messagingSenderId: "329242574122",
  appId: "1:329242574122:web:b99c7698d11f212a527253",
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const db = getFirestore(app);

export { db };
