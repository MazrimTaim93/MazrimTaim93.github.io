using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyBulletMovement : MonoBehaviour {

    public float moveSpeed = -8;
    AudioSource hit;

    // Use this for initialization
    void Start ()
    {
        //destroy after 1 second
        Destroy(gameObject, 1.3f);
        hit = GetComponent<AudioSource>();
    }
	
	// Update is called once per frame
	void Update ()
    {
        //move straight down
        transform.Translate(new Vector3(0, moveSpeed * Time.deltaTime, 0));
        //destroy self on contact with any other game object
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        //Destroy bullet, unless its just touching the parent object
        if (collision.gameObject.tag != "Enemy")
        {
            hit.Play();
            Destroy(gameObject, 0.3f);
        }

        if (collision.gameObject.tag == "Obstacle")
        {
            Destroy(collision.gameObject);
        }
    }
}
