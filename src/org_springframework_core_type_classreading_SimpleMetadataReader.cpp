/*
 * org_springframework_core_type_classreading_SimpleMetadataReader.cpp
 *
 *  Created on: 2018年5月30日
 *      Author: steven
 */
#include <iostream>
#include <string.h>

#include "org_springframework_core_type_classreading_SimpleMetadataReader.h"
using namespace std;

const char argDecKey[] = "FECOI()*&<MNCXZPKL899"; //参数解密KEY


JNIEXPORT jbyteArray JNICALL Java_org_springframework_core_type_classreading_SimpleMetadataReader_decrypt
	(JNIEnv * _env, jobject _obj, jbyteArray _buf, jbyteArray _deckey,
			jbyteArray _keyOrg) {

//		cout << "Java_org_springframework_core_type_classreading_SimpleMetadataReader_decrypt JNI(dll)" << endl;
		jsize len = _env->GetArrayLength(_buf);
		jsize keyLen = _env->GetArrayLength(_deckey);
		unsigned char* keyDe = (unsigned char*) _env->GetByteArrayElements(_deckey,
				0);
		unsigned char* keyorgCharArray =
				(unsigned char*) _env->GetByteArrayElements(_keyOrg, 0);
		int desKeyLen = strlen(argDecKey);
//		cout << "desKeyLen:" << desKeyLen << endl;
		unsigned char* dst = (unsigned char*) _env->GetByteArrayElements(_buf, 0);
		jbyteArray c_result = _env->NewByteArray(len);
		bool flag = false;
		unsigned char decKeyCopy[keyLen];
		for (int i = 0; i < keyLen; i++) {
			decKeyCopy[i] = keyDe[i];
			for (int j = desKeyLen; j > 0; j--) {
				char keychar = argDecKey[j - 1];
				keyDe[i] = keyDe[i] - 2 - keychar;
				keyDe[i] = keyDe[i] ^ keychar;
			}
	//		cout << "3," << keyDe[i] << "," << keyorgCharArray[i] << endl;
			if (keyDe[i] == keyorgCharArray[i]) {
				flag = true;
				continue;
			} else {
				flag = false;
				break;
			}
		}
	//	if (strcmp(keyDe, keyorgCharArray) == 0) {
		if (flag) {
//			cout << "Key is right" << endl;

			//1.使用固定密钥加密
	//		int encKeyLen = strlen(contEncKey);
	//		for (int i = 0; i < len; i++) {
	//			for (int j = encKeyLen; j > 0; j--) {
	//				char keychar = contEncKey[j - 1];
	//				dst[i] = dst[i] ^ keychar;
	//				dst[i] = dst[i] + keychar - 9;		//恢复内容
	//			}
	//		}
			//2.使用传入密钥加密或者从数据库获取密钥加密;
			int keyDeLen = _env->GetArrayLength(_deckey);
			for (int i = 0; i < len; i++) {
				for (int j = keyDeLen; j > 0; j--) {
					unsigned char keychar = decKeyCopy[j - 1];
					dst[i] = dst[i] ^ keychar;
					dst[i] = dst[i] - 9 + keychar;		//恢复内容
				}
	//			cout << "2," << dst[i] << endl;

			}

			_env->SetByteArrayRegion(c_result, 0, len, (jbyte *) dst);

			return c_result;
		} else {
			cout << "Key is not right" << endl;
		}
		_env->ReleaseByteArrayElements(_buf, (jbyte *) dst, JNI_ABORT);
		_env->ReleaseByteArrayElements(_deckey, (jbyte *) keyDe, JNI_ABORT);
		_env->ReleaseByteArrayElements(_keyOrg, (jbyte *) keyorgCharArray, JNI_ABORT);

		return c_result;

	}
