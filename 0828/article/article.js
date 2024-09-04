import { db } from "../app.js";
import {
  collection,
  getDocs,
  orderBy,
  query,
  getDoc,
  doc,
  Timestamp,
  addDoc,
  updateDoc,
  deleteDoc,
} from "https://www.gstatic.com/firebasejs/10.12.2/firebase-firestore.js";

// collection
// 문서의 그룹을 가져올 때 사용 (문서 하나만 가져올 경우는 doc을 사용)

// getDocs

// orderBy - 정렬관련 날자 추가할 때

// query - 특정 조건이 사용가능

async function getArticles() {
  try {
    // firebase db에 접근해서 articles를 가져온다
    const collectionRef = await collection(db, "articles");
    // 리스트를 orderBy로 정렬해서 가져오기
    const q = await query(collectionRef, orderBy("createdAt", "desc"));
    const querySnapShot = await getDocs(q);
    console.log(querySnapShot);

    const articles = querySnapShot.docs.map((doc) => {
      return { id: doc.id, ...doc.data() };
    });
    return articles;
  } catch (error) {
    return error.code;
  }
}

async function getArticle(id) {
  try {
    const docRef = await doc(db, "articles", id);
    const docSnapshot = await getDoc(docRef);
    if (docSnapshot.exists()) {
      const article = {
        id: docSnapshot.id,
        ...docSnapshot.data(),
      };
      return article;
    } else {
      return 404;
    }
  } catch (error) {
    return error.code;
  }
}

async function createArticle(title, content) {
  const timestamp = Timestamp.fromDate(new Date());
  const newArticle = {
    title: title,
    content: content,
    createdAt: timestamp,
    updatedAt: timestamp,
  };
  try {
    const docRef = await addDoc(collection(db, "articles"), newArticle);
    return docRef.id;
  } catch (error) {
    return error.code;
  }
}
// const parsedCreatedAt = new Date(result.createdAt.seconds * 1000);

async function updateArticle(id, newTitle, newContent) {
  const newArticle = {
    title: newTitle,
    content: newContent,
    updatedAt: Timestamp.fromDate(new Date()),
  };
  try {
    await updateDoc(doc(db, "articles", id), newArticle);
    return id;
  } catch (error) {
    return error.code;
  }
}

async function deleteArticle(id) {
  try {
    await deleteDoc(doc(db, "articles", id));
  } catch (error) {
    return error.code;
  }
}

export { getArticles, getArticle, createArticle, updateArticle, deleteArticle };
