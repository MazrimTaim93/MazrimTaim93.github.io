using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyRowMovement : MonoBehaviour {

    public float horizSpeed = 2;
    public float vertSpeed = -2;

    // Use this for initialization
    void Start ()
    {
		
	}
	
	// Update is called once per frame
	void Update ()
    {
        //move
        transform.Translate(new Vector3(horizSpeed * Time.deltaTime, 0, 0));

        //switch directions before hitting the edge of the screen
        if (transform.position.x <= -3 || transform.position.x >= 3)
        {
            transform.Translate(new Vector3(0, vertSpeed * Time.deltaTime, 0));
            horizSpeed *= -1;
        }
    }
}
